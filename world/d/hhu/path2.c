// Room: /d/hhu/path2.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ��ͨ��Ӻ���ѧ�������
    ԶԶ���Ѿ����Կ����Ӻ���ѧ��У����
    ���ܷ羰������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hhugate.c",
  "east" : __DIR__"path1.c",
]));
	set("no_clean_up", 0);

	setup();
}
