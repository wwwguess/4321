// Room: /d/choyin/bridge1.c

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
  "north" : __DIR__"s_street1",
  "east" : __DIR__"bridge2",
]));
	set("outdoors", "choyin");
        set("objects", ([
                __DIR__"npc/visitor" : 4 
        ]) );


	setup();
	replace_program(ROOM);
}
