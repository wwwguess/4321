// Room: /d/hhu/hhupath1.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���������ںӺ���ѧУ�ڵ��������
    ���ܷ羰������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hhupath2.c",
  "east" : __DIR__"hhugate",
]));
	set("no_clean_up", 0);

	setup();
}
