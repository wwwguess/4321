// Room: /d/choyin/tomb2.c

inherit ROOM;

void create()
{
	set("short", "�������ڲ�");
	set("long", @LONG
�������������������ڲ�����ı������������涼���̸���ڵ���
��������������һ��Ǭ�ݣ��ƺ�����˯�������ӣ������ĳ���ͨ������
����һ�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"tomb1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
