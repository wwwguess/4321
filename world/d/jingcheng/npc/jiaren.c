// jiaren.c
// Made by ysgl (1997.10.23)

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("���¼���", ({"qingyi jiaren", "jiaren" , "qingyi" }));
	set("gender", "����"); 
	set("long", 
	"һ������ͨͨ�����¼��ˣ����ϴ���Ц�ݡ�\n");    
	set("age", 35);
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
}

