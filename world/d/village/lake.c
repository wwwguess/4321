// Room: /d/village/lake.c

inherit ROOM;

void create()
{
	set("short", "���ݺ�");
	set("long", @LONG
���������ݺ��ĺ��ģ�������˿˿����������Χ���ó��棬������
�����ļ�������ϸ������׿�ȥ�����ļ��׹�һ��������뿴����������
��Ǳ�����(dive)�������Ǹ�����һ��Ҫ��ȫ��һ������Զ�������ʵ�Ⱥ
ɽ�����߰��ϵ�����ƺ�������ȱȻ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lakeside",
]));
	set("no_clean_up", 0);

	setup();
	
}

void init()
{
	add_action("do_paddle","paddle");
	add_action("do_dive","dive");
}

int valid_leave(object me,string dir)
{
	if( dir=="east" )
		return notify_fail("����վ�ڴ�ͷ������һС���ͻ������У��㲻�������ɣ�\n");
	return valid_leave( me,dir);
}

int do_paddle(string arg)
{
        if(!arg || arg=="")
                return notify_fail("��Ҫ��ʲô��\n");
        if( arg!="boat" && arg!="��" )
                return notify_fail("���������뻮ʲô��\n");
        message_vision("$N�㻮��˫����С�������򰶱�Ưȥ��\n
", this_player());
        write("�����ڻ��������ߡ�\n");
        this_player()->move(__DIR__"lakeside");
        return 1;
}

int do_dive(string arg)
{
	message_vision("$N��������һ������һ������Ǳ��ˮ�У�\n", this_player() );
	write("��ԽǱԽ�ͻȻ��ǰһ����һ�����׷�������������ȭһ�ң���\n
               ���׾�Ȼ���ˣ�ԭ����һ�����������ˮ�������һ���Ҷ��С�\n");
	this_player()->move(__DIR__"lakebottom1");
	return 1;
}
