#include <room.h>  
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
������ȥ���������б̲����ԣ�������ɽ��������һƬɽ��ˮɫ��������һ����
�ŷ�����һƬ��ˮ��㲻��ʮ���ɣ��������ɽ��ˮ�����ǻ��ڱ��ϵĵ���ͼ����
ֻ�ǻ���ίʵ̫�����棬Զ���������������磬��ɫ�����������Σ�ʹɽɫ������
�縲�Դ䣬�Ͱ���Ʈ����Ǽ�ֻ���Գ�঵���죬Ҳ������Ҫ�Ʊڷɳ������Ƴ���
�����̲�֮�ϣ�Ҳ�м�ֻ�׶측����䣬����һ��С������ķ���Ʈ��ˮ�ϣ�ֻ��
���������ɴ�ʹ�����ˮ�棬˭Ҳ�Ʋ������������ֻ�Ƽ�һ�����̴���һ������
֮��Ʈ���Դ�������ɢ������
LONG
  );
  	set("exits/south" ,__DIR__"blkroom");
    set("objects",([
    	__DIR__"npc/zhuo" : 1,
    	__DIR__"npc/feng" : 1,
    ]) );

    setup();
 }
void reset()
{   
	object *inv;
	int i,no_reset;
	inv=all_inventory(this_object());
	no_reset=0;
	for (i=0;i<sizeof(inv);i++)
	{
	    if(base_name(inv[i])==__DIR__"npc/lishi")
		{
			if (!inv[i]->is_fighting())                  
		    	destruct(inv[i]);
		    else
		    	no_reset=1;
		}
		else
		if(base_name(inv[i])==__DIR__"npc/feng2" )
		{
			if (!inv[i]->is_fighting())
				destruct(inv[i]);
			else  
				no_reset=1;
		}
	}
	if(!no_reset) ::reset();
}