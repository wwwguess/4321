// Room: /d/city/street13.c
inherit ROOM;
void create()
{
        set("short", "��ʦ�ֵ�");
        set("long", @LONG
��������ʦ�Ĵ���ϡ������Ǿ�ʦ�������ţ���ȥ���˲�ʱ��
������ϱ��Ǿ�ʦ�ļ�������Ѻ��һЩ��Ҫ�ķ��ˡ�վ�������
��������������俽���˵�Ƥ�����ͷ��˵Ĳҽ�����
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
             "west"   :    __DIR__"westdoor2",
             "east"   :    __DIR__"street12",]));
//             "south"  :    __DIR__"jial",]));
        set("objects", ([
                "d/snow/npc/scavenger": 1 ]) );

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}
