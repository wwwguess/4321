// shanlu2.c 
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
		"southdown" : __DIR__"shanlu1",
		"northup" : __DIR__"damen",
	     
	]));
	setup();
	replace_program(ROOM);
}


