// Room: /d/snow/jiulou_2f.c

inherit ROOM;

void create()
{
        set("short", "̫�׾�¥��¥");
        set("long", @LONG
��������̫�׾�¥�Ķ�¥����¥�����������ڴˡ�������ͷ
�Ŀ��˶������������֡��ڴ˾�����������һЩ��ٹ��壬һЩΪ
���ٵĸ����ӵܾ����˴���׵���Ϣ��ǽ����һ��¥��ͨ��һ¥��
������
LONG
        );
        set("exits", ([ 
		"down":		__DIR__"jiulou",
        ]));

/*        set("objects", ([
                __DIR__"npc/waiter":       1,
                ]));
*/
        setup();
}

