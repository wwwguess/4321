//Room:/d/heimuya/midao/midao51.c 
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
          "east" : __DIR__"midao52",
           "south" : __DIR__"midao62",
           "west" : __DIR__"midao50",
         ]));
        setup();
        replace_program(ROOM); 
}
// the end of the file 

