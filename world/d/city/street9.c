// Room: /d/city/street9.c
inherit ROOM;
void create()
{
        set("short", "��ʦ�ֵ�");
        set("long", @LONG
�����������ھ�ʦ�Ĵ���ϡ����߾��Ǿ�ʦ�Ķ�һ���ˣ���Լ
�����ٱ��Ѳ����˵�ߺ����������ı����Ǿ��ǵ������꣬��˵��
���ϰ������ϵ�������Ʒ���ڴ˵ꡣ�ӵ����߳����˶���һ������
�����ģ����
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
             "east"  :    __DIR__"eastdoor1",
             "north" :    __DIR__"weapon",
             "west"  :    __DIR__"street8",]));
        set("objects", ([
                "d/snow/npc/scavenger": 1 ]) );

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}
