// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "����վ");
	set("long", @LONG
�����ǲ�ʯ���ڴ�ڵĹ���վ��һ��СС��ľ�����ڶ��ߣ��Ա���һ
����ɽ��б�¡�·����һ�ھ����յ���ͣ����������ʯ�ϵĳ���������һ
��������ʯ���·��һ·��ɽ�������ȥ��
 
LONG
	);
    set("exits", ([
    "northeast" : __DIR__"station1",
    "west" : __DIR__"path5",
]));
	set("objects", ([
    __DIR__"npc/worker2" : 1,
	]) );
    set("resource/water",1);

	setup();
	replace_program(ROOM);
}

