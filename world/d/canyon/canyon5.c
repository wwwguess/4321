// ROOM:__DIR__"canyon5"

inherit ROOM;
void create()
{
        set("short","����С·");
	set("long",@LONG                                   
�ϱ߼�Ϊ���չصĹؿڣ���Ƭŵ�������(door)�������ɹ��ڴ򿪿�
�����Խ��룬�����࿴ȥ����դ��ӳ������˫������ת�����࣬�����Ļ�
��һƬ��ͺͺ��ɽ�ڣ����ɵ�ʹ��������뿪����ط���
LONG
	); // eof(long)
	
	set("exits",([ /* sizeof()==1 */
		"south" : __DIR__"canyon6",	
		"north" : __DIR__"canyon4",
	]) ); //eof(exits)

	set("item_desc", ([
		"door": "��޴�������⼣�߰ߣ��������¿��ϵģ������Ѿ��߸ߵ�̧��\n"
			"����ʧ�����£�����ʲô�������ᱻ�ұ⡣\n",
	]) );	
	setup();
	
	replace_program(ROOM);
} //EOF
