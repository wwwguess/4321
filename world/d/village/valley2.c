// Room: /d/village/valley2.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
��������������һ��С·�������ͽ������и����µ�С��ׯ���Ӵ�
ׯ��������С·����ϡ�٣����ܾ��������д���ɹ�����ȵ�ɽ�롣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"valley1",
  "east" : __DIR__"road6",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
