// Room: /d/village/valley1.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
��������������һ��С·�������Ϻͱ����졣ɽ������ľ��ï����
�����𣬶��������������ݺ�������ˮ�����ڣ�����߰���û�д�������
�ɴ˵����ϡ�����ԼԼ�ؿ��ļ��������µĴ�ׯũ�ᡣ
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"valley2",
  "eastdown" : __DIR__"lakebottom2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
