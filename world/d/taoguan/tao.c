// Room: /d/snow/tao.c

inherit ROOM;

void create()
{
        set("short", "éɽ����");
        set("long", @LONG
����һ����ɭ�ĵ��ۣ�������ǰ�������Ϲ��������������,һλò������
�ĵ�ʿ�������������ǳ������ġ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"eroad3",
]));
        set("objects", ([ /* sizeof() == 2 */
                CLASS_D("taoist") + "/taolord":1,      
                __DIR__"npc/tao_first" : 1,
               __DIR__"npc/tao_2" : 1        
         ]));
        set("valid_startroom", 1);
        setup();
        replace_program(ROOM);
}
