// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","�ػ���");
	set("long", @LONG
�ذ�����ˮĥʯ�̳ɡ�����ǽ�Ϲ��������ֻ���
�����ǽ�ϸ߸ߵع���һ����ң����顰�ػ��á�
���֡�������һ��̫ʦ��.
LONG
	);

	set("exits", ([
		"out"  :__DIR__"yst",
		"north" :__DIR__"dht2",
	]));

	set("valid_startroom", 1);

	set("objects", ([ 
		__DIR__"npc/wangcheng" : 1,
        ]));
	setup();
}

