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
  "north" : __DIR__"wvillage0",
    "south" : __DIR__"wvillage2",
      "west"  : __DIR__"wvillage13",
        "east"  : __DIR__"wvillage5",
]));

        set("outdoors", "girlvillage");
        
        setup();
        replace_program(ROOM);
        
}
                                