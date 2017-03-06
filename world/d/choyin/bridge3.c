// Room: /d/choyin/bridge3.c

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
  "south" : __DIR__"bridge2",
  "east" : __DIR__"bridge4",
]));
	set("no_clean_up", 0);
	set("outdoors", "choyin");
	set("objects", ([
		 __DIR__"npc/visitor" : 4
 	]) );

	setup();
	replace_program(ROOM);
}
