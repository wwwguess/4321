// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

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
                __DIR__"obj/m_ji": 6,
        ]) );

	set("exits", ([
		"south" :__DIR__"rjt1",
	]));
	setup();
}

void init()
{
add_action("do_feng","feng");
}

int do_feng()
{
tell_object( this_player(), "welcome my boy.  heihei \n");
this_player()->move( __DIR__ "xxt8" );
return 1;
}

