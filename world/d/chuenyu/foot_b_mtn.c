// Room: /d/chuenyu/foot_b_mtn.c

inherit ROOM;

void create()
{
        set("short", "����ɽ��");
        set("long", @LONG
�����ڼ��ѵ�����Ψһͨ��ɽ����С·�ϡ�·�߶��źܶ���Ŀ
�����ľ�ʯ������������ǿ�Ĵ�ʯ���м��˳�����������
����Կ���ɽ���Ǳ��Ĵ���������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
        "down" : __DIR__"base_b_m",
          "up" : __DIR__"high_b_mtn",
          ]));
          set("outdoors", "chuenyu");
          
          setup();
          replace_program(ROOM);
}
                  
