// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","����̲");
	set("long", @LONG
�����������������̲,��ˮ���˹���һ����,ˮ���ļ�
��ˮ�����ʯ�������������.������һ����Ҳû��,ֻ
��һֻľ��ϵ�ڽ���,�����и����°׿���ҹ�.
LONG
	);

	set("exits", ([
                "west" :__DIR__"xxt7",
	]));
         set("objects",([
                __DIR__"npc/shaogong1" : 1,
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

