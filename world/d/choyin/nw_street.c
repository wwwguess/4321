// Room: /d/choyin/nw_street.c

inherit ROOM;

void create()
{
	set("short", "ʯ��յ�");
	set("long", @LONG
�����������������ߵ�ʯ��յأ���Ϊ�����ĸ���Χ̫�㣬�����
������Χʮ���ɶ�û�а취�Ƿ��ӣ������������ʯ�壬ƽʱ�㵱����
��ɢ�����ĵط���
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"w_street4",
  "south" : __DIR__"w_street3",
  "east" : __DIR__"n_street3",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
