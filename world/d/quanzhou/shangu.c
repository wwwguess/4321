// Room: /d/quanzhou/wuminggudi.c
// By diablo 97 11 

inherit ROOM;

void create()
{
    set("short", "�����ȵ�");
    set("long", @LONG
������һ��ɽ�ȵĵײ�����ʱ����һ�����������΢��˻�ƣ�����Խ��
�����������������е�����Ʈ��һ��ʪ����һ��ˮ���ɱ�����������
    �����Ǹ�ɽ�£���������һ������ɭɭ�Ķ�Ѩ��������һ��Сé�ݡ�
LONG
    );
    set("outdoors", "quanzhou");

    set("exits", ([
	"southup" : __DIR__"nanhu",
	"northup" : __DIR__"caocong",
    ]));
                                                    
    set("objects", ([
        __DIR__"npc/choudiao" : 1]));

    
    setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "northup" && objectp(present("chou diao", environment(me))))
                return notify_fail(
"���������Į����ס�����ȥ·��\n");
	if ( dir == "northup" ) 
		return notify_fail(
"��ǰ��һƬ�����ߵĲݴԣ�����ԥ��һ�£����˻�����\n");
        return ::valid_leave(me, dir);
}



