// Room: /d/snow/inneryard.c

inherit ROOM;

void create()
{
	set("short", "�쾮");
	set("long", @LONG
  �����Ǵ��������е��쾮�������߿��Ե�������������
���鷿���ϱ����д����˵��᷿������һ������ͨ������
��Ժ���쾮���������滨���ˣ��м�����һ��ʯ��(pill
ar)�������ƺ�������
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
		"pillar" : "ʯ���Ͽ���������ָ�졢������������â���ԡ�������硣
",
]));
	set("outdoors", "snow");
	set("exits", ([ /* sizeof() == 5 */
		"west" : __DIR__"schoolhall",
		"north" : __DIR__"nyard",
		"south" : __DIR__"guestroom",
		"east" : __DIR__"innerhall",
]));
     set("no_clean_up",0);
     set("outdoors", "snow");
replace_program(ROOM);
	setup();
}
