// Room: /d/village/road4.c

inherit ROOM;

void create()
{
	set("short", "��ʯС·");
	set("long", @LONG
��ʯС·����û����ľ�������Ӳ����ҡ�ڣ�·�ϵ�ʯͷ�����˲�ĥ��
�ܹ���������ֵ���ƽʱ���������ȴ�ǳ�ϡ�٣�С·�������쿪ȥ������
��һƬ���Ĺϵأ�������һ��ũ�ᡣ
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"farmhouse1",
  "west" : __DIR__"road5",
  "southdown" : __DIR__"melonfarm",
  "east" : __DIR__"road3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
