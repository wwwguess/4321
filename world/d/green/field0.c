// Room: /d/green/field0.c

inherit ROOM;

void create()
{
	set("short", "С�㳡");
	set("long", @LONG
����һ��СС�Ĺ㳡�����������и�����Ĵ�ʯ�顣�㳡��Χ�м���
���ӣ����������ϱ��Ƕ�ľ����Ϊ�ر�������һ��խխ��С���ӣ�����
������������ʯ���Ŀյء�������һ�ô���������һ����ͤ������ڹ㳡
�ϡ�
LONG
);
	set("exits", ([ /* sizeof() == 4 */
  "west" : "/d/green/path8",
  "south" : "/d/green/house4",
  "north" : "/d/green/house2",
  "east" : "/d/green/field1",
]));

	setup();
	replace_program(ROOM);
}
