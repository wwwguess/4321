
inherit ROOM;

void create()
{
	set("short", "��ʯС��");
	set("long", @LONG
����һ����ͨ����ʯС������������������ȥ��·������һƬ�������֣���
���紺ʱ�ڣ�������������֦ͷ��������һ��Сʯ�ţ���������ͨ���س�
��·��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : "/d/yulan/road2",
  "southwest" : "/d/yulan/road",
]));

	setup();
	replace_program(ROOM);
}
