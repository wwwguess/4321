// Room: /d/hhu/hohai-room2f.c

inherit ROOM;

void create()
{
	set("short", "�Ӻ���");
	set("long", @LONG
�Ӻ����ǺӺ���ѧ�ڵĴ���֮һ
    ���������ڴ˰칫��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"hohai-room3f",
  "down" : __DIR__"hohai-room",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/Pro.Wang" : 1,
]));
	set("no_clean_up", 0);

	setup();
}
