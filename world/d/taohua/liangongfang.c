// Room: /d/new_taohua/liangongfang.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����ɲ���Ƥ����ľ��ɡ������������٣����ݺ�ٸ�һ��������
���ڷǳ��տ���ֻ�м������š�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wuqiku",
  "east": __DIR__"houhuayuan",

]));                               
	set("objects", ([
                
                __DIR__"npc/di-zi1" : 3,
	       
 ]));

        setup();
        replace_program(ROOM);
}
