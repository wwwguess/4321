// Room: /d/choyin/bridge4.c

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
		"south" : __DIR__"bridge5",
		"west" : __DIR__"bridge3",
	]));
	set("outdoors", "choyin");
	set("objects", ([
		__DIR__"npc/girl" : 1,
		__DIR__"npc/maid" : 2,
	]) );

	setup();
	replace_program(ROOM);
}
