// Room: /d/taohua/wuqiku.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����ɲ���Ƥ����ľ��ɡ������������٣����ݺ�ٸ�һ��������
���Ϲ��м���������������һ�鰸������б����һ֧���
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yaopinfang",
  "east": __DIR__"liangongfang",

]));

	   set("objects", ([
                "/obj/weapon/zhujian" : 3]));

        setup();
        replace_program(ROOM);
}

   
