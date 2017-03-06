// Room: /d/choyin/bridge2.c

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
		"west" : __DIR__"bridge1",
		"north" : __DIR__"bridge3",
	]));

	set("outdoors", "choyin");
	set("objects", ([
		__DIR__"npc/scholar" : 2 
	]) );

	setup();
	replace_program(ROOM);
}
