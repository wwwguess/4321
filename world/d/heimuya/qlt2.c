inherit ROOM;
void create()
{
        set("short", "����������");
        set("long", @LONG
����һ�������ʽ��������е�Ĵ����ң���ʽ�������������ࡢ��
�̡����η���һ�𣬲��Ҳ��õ�һ����Ⱦ�������ҵĳ���������ϱߣ�
LONG
        );
	set("objects", ([
                __DIR__"obj/m_sword": 6,
        ]) );
	set("exits", ([
		"south" :__DIR__"qlt1",
	]));
	setup();
}
void init()
{
add_action("do_1","1");
add_action("do_2","2");
}
int do_1()
{
object me;
this_player()->move("/d/jingcheng/postoffice");
return 1;
}
