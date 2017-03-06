// Room: /d/temple/ladder2.c

inherit ROOM;

void create()
{
	set("short", "ʯӢ��ʯ��");
	set("long", @LONG
��������һ��������ʯӢ�ҽ�����, ���ݵ�������ֲ��һ�Ÿ���
��������̧ͷ������������������ͦ�ε�ɽ��, ������Ʈ���ɽ����
, ������һ����ΰ�İ�ɫ¥��
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guest" : 1,
]));
	set("outdoors", "temple");
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"ladder1",
  "northdown" : __DIR__"ladder3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
