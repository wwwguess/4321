//Room:/d/heimuya/midao/midao50.c 
//write by dfbb@hero
//Date: 1/25/96
inherit ROOM;

void create()
 {
        set("short", "�����ܵ�");
        set("long", @LONG ����������,ֻ��ǽ���ϵ���һյ�谵���͵�
 ��ʪ����ζ����ʮ�ֲ����,ֻ�����߳������ط�.
LONG );
        set("exits", ([
          "east" : __DIR__"midao51",
           "south" : __DIR__"midao61",
           "west" : __DIR__"midao49",
         ]));
        setup();
        replace_program(ROOM); 
}
// the end of the file 

