#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>

#define MAJORNO 190
#define MINORNO 0
#define CHAR_DEV_NAME "vDev1"
#define SUCCESS 0

static struct cdev *veda_cdev;
static dev_t mydev;
static int count = 1, inuse = 0;


static int char_dev_open(struct inode *inode, struct file *file)
{	
	if(inuse) {
		pr_err("Device busy %s",CHAR_DEV_NAME);
		return 0;
	}
	inuse = 1;
	printk("open done\n");
	return 0;
}

static int char_dev_release(struct inode *inode, struct file *file)
{
	inuse = 0;
	pr_info("relese\n");
	return SUCCESS;
}

static ssize_t char_dev_write(struct file *file,const char __user *buf,size_t lbuf,loff_t *offset) 
{
	pr_info("write invoked\n");
	return SUCCESS;
}

static ssize_t char_dev_read(struct file *file,char __user *buf,size_t lbuf,loff_t *offset) 
{
	pr_info("read invoked\n");
	return SUCCESS;
}

static struct file_operations char_dev_fops = {
	.owner = THIS_MODULE,
	.write = char_dev_write,
	.open = char_dev_open,
	.read = char_dev_read,
	.release = char_dev_release
};

static int char_dev_init(void)
{
	int ret; 
	mydev = MKDEV(MAJORNO,MINORNO);
	register_chrdev_region(mydev, count, CHAR_DEV_NAME);

	/* allocate cdev instance */
	veda_cdev = cdev_alloc();

	/*initialize cdev with fops object */
	cdev_init(veda_cdev, &char_dev_fops);
	
	/* register cdev with vfs(devtmpfs) */
	ret = cdev_add(veda_cdev, mydev, count);
	if(ret < 0) {
		pr_err("ERROR registering device driver");
		return  ret;
	}
	pr_info("Device registered %s\n", CHAR_DEV_NAME);
	return SUCCESS;
}
static void char_dev_exit(void)
{
	/* remove cdev */
	cdev_del(veda_cdev);

	/* free major/minor no's used */
	unregister_chrdev_region(mydev, count);
	pr_info("Driver unregistered");
}

module_init(char_dev_init);
module_exit(char_dev_exit);

MODULE_AUTHOR("rohith4862@gmail.com");
MODULE_DESCRIPTION("LKD_CW: Character Device Driver - Test");
MODULE_LICENSE("GPL");

