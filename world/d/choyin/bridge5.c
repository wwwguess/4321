// Room: /d/choyin/bridge5.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ���������������ţ�������������Ӷ���������ׯ��������
�����سǣ�������������ʹ����������������˯��ɢ�����Ŷ����ܣ�
����Ʈ���������ĸ�Ƽ����Ƽ�����в����޺��������ȥ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"bridge4",
 "east" : __DIR__"entrance",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
