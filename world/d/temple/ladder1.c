// Room: /d/temple/ladder1.c

inherit ROOM;

void create()
{
	set("short", "ʯӢ��ʯ��");
	set("long", @LONG
�����Ľ���Ҳ�ս����˾�ͷ, ���ݵľ�ͷ������һ��ɽ��, ɽ��
�����ɷ����д��������, �����Ծ������Ե����ƷǷ���ɽ�紵����
��˿˿�ĺ���, �����йɸߴ���ʤ���ĸо���
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/little_taoist1" : 1,
]));
	set("outdoors", "temple");
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"entrance",
  "eastdown" : __DIR__"ladder2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
