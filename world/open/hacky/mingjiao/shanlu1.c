// shanlu1.c 
// by yuer

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
      �����ڶ��͵�ɽ·�ϣ����߶������£�һ��С�ģ�
     �ͻ����ȥ������ʮ���ն�
LONG
	);
        set("outdoors", "mingjiao");

	set("exits", ([
		"southdown" : __DIR__"banshanmen",
		"northup" : __DIR__"shanlu2",
	     
	]));
	setup();
	replace_program(ROOM);
}


