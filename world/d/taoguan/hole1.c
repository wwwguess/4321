
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ڰ���ʪ��������Ĳ���о�Խ��Խ�ء�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hole2",
  "south" : __DIR__"hole",
]));
	setup();
        replace_program(ROOM);
}
