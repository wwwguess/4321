// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","��");
	set("long", @LONG
	����ͨͨ��һ���,�����˲��,�����Ȼ���Ͻ������
LONG
	);

	set("exits", ([
		"west"  :__DIR__"dingfeng5.c",
	]));

    set("sleep_room",1);
	setup();
	replace_program(ROOM);
}

