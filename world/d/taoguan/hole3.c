
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ڰ���ʪ���ڱ�����һ˿�����ս�������������һ��
ϣ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hole4",
  "south" : __DIR__"hole2",
]));
	setup();
        replace_program(ROOM);
}
