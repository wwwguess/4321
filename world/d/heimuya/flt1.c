// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","������");
	set("long", @LONG
�ذ�����ˮĥʯ�̳ɡ�����ǽ�Ϲ��������ֻ���
�����ǽ�ϸ߸ߵع���һ����ң����顰�����á�
���֡�������һ��̫ʦ��.
LONG
	);

	set("exits", ([
		"out"  :__DIR__"yst",
		"north" :__DIR__"flt2",
	]));

	set("valid_startroom", 1);

	set("objects", ([ 
                __DIR__"npc/tongbaixiong" : 1,
        ]));
	setup();
}

