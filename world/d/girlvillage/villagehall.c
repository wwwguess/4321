inherit ROOM;

void create()
{
        set("short", "�����ɴ���");
        set("long", @LONG
��������ʼ��������ǰ������������ѱ鲼���¡�������
���������������������ϻ�ͯ�ľ��硣
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
      "north" : __DIR__"villagepath",
      "west"  : __DIR__"wvillage15",
      "east"  : __DIR__"gpalace",
]));
        set("outdoors", "girlvillage");
        set("valid_startroom", 1);
        set("objects", ([
                 __DIR__"npc/master" : 1 ]) );
                 
        setup();
        
}
                               