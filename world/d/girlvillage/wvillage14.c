inherit ROOM;

void create()
{
        set("short", "Ů�˴�");
        set("long", @LONG
��äĿ���������ޱ߼ʵ�Ů�˴���������ܣ����ܵľ�ɫ
������߹��ĵط�����һ��������������Ů�˴�����߿��ٴ�����
����Ͷ���������۹⡣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "north" : __DIR__"wvillage13",
          "south" : __DIR__"wvillage15",
            "west"  : __DIR__"wvillage10",
              "east"  : __DIR__"wvillage4",
]));
        set("outdoors", "girlvillage");
        
        setup();
        replace_program(ROOM);
        
}
                      
                        