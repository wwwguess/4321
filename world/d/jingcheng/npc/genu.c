//by dwolf
               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("Ů��", ({ "nu hai" , "girl"  }));
	set("title","��Ů");
	set("long",
	"һ���¿������ĸ�Ů���������磬ֻ�п�����Ϊ����\n");
	set("gender", "Ů��");
	set("age", 18);
	set("attitude", "peaceful");  
	set("per", 30);
	set("combat_exp", 500);
	setup();
       		
	carry_object(__DIR__"obj/cloth")->wear();
	
}

