// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","����̲");
	set("long", @LONG
�����������������̲,ɽʯһƬѪ��,���㲻����һ��˵������
���Ƹо�,������һ����Ҳû��,ֻ��һֻľ��ϵ�ڽ���,������
�����°׿���ҹ�.��Ҫô�Լ���(swim)��ȥ,Ҫô��������һ��
��ι���.
LONG
	);

	set("exits", ([
                "east" :__DIR__"xxt4",
	]));

	 set("objects",([
                __DIR__"npc/shaogong" : 1,
        ]));

	set("outdoors", "heimuya");
	setup();
}

void init()
{
        add_action("do_swim", "swim");
}

int do_swim()
{
        object me;
        me = this_player();
        message_vision("$N����Σ������ˮ�У���԰���ȥ��\n", me);
        me->move(__DIR__"river");
        return 1;
}

