 // houhuayuan2.c
// by yuer
inherit ROOM;
void create()
{
        set("short", "��԰");
        set("long", @LONG
�����ǹ������ĺ�԰�������˻��ݡ�����Сͯ���ڽ���
������һ�����ŵ�С�ݡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  
  "east":__DIR__"houhuayuan1",
  
]));
        
       
        set("outdoors", "mingjiao" );
        setup();
        replace_program(ROOM);
}

