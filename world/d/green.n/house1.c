// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "�����ļ�");
	set("long", @LONG
����һ����ͨ����լ����С����������ض���һ���ŵ�ʯ�壬ǽ����
������ʽ�����ĵ�̣��и�Ĺ��ߡ��ݽǷ�����ʽ�ĳ�Ʒ�����Ʒ��ʯ��
��ʯ�Ρ�Ĺ���ȡ�
 
LONG
	);
    set("exits", ([
    "south" : __DIR__"path8",
]));
	set("objects", ([
    __DIR__"npc/worker1" : 1,
	]) );


	setup();
	replace_program(ROOM);
}
