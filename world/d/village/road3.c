// Room: /d/village/road3.c

inherit ROOM;

void create()
{
	set("short", "��ʯС·");
	set("long", @LONG
����һ��ͨ��һ����ׯ����ʯС·��·������һ��С����(tablet)��
���ӿ�����������ʱ�����ɹ���ܣ������ò�������������ȥ������Ƭ
�ϵأ������͵���������о������ˡ������������ͽ��˴��ӣ��򶫵�
����·�ڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"road4",
  "east" : __DIR__"road2",
]));
	set("no_clean_up", 0);
	set("item_desc", ([
		"tablet":"����ǿ�ֱ��������ģ�����ּ���������\n"
	]) );
	setup();
	replace_program(ROOM);
}
