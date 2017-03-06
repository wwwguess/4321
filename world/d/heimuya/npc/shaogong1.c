// boater.c
// write by dfbb@hero
// Tue Dec 26 18:10:16 CST 1995
#include <ansi.h>

inherit NPC;

string	cross_river();

string *make_msg = ({
    HIG "����̲ˮ���ļ�,�����ҹ��ļ����ܺ�\n\n" NOR,
    HIG "�����������һ��,�񷤱��뿪����\n\n" NOR,	
    HIG	"���ǵ����Ѿ��쵽������\n\n" NOR,
    HIG "���ǵ����Ѿ����˽���\n\n" NOR,
    HIG "���ǵ����Ѿ����˽���\n\n" NOR,
    HIG "���ǵ��񷤿쿿����\n\n" NOR,
    HIG "���ڵ���!!!������һԾ,�����ϰ�ȥ \n\n" NOR,
});


void create()
{
        set_name("�ҹ�", ({ "shaogong" }) );
        set("title", "�ɿ�");
        set("gender", "����" );
        set("age", 60);
        set("long", "�����Ƥ��ɹ����ڣ����ϵĲ�ɣ�Ƕ���ڶɵĺۼ���\n");
	set("str", 27);
        set("combat_exp", 1500);
        set("attitude", "heroism");
        set_skill("unarmed", 40);
        set_skill("parry", 50);
        set_skill("dodge", 30);
	set_skill("spear", 40);
	set_skill("mo-qiang-jue", 40);
	map_skill("spear", "mo-qiang-jue");
	map_skill("parry", "mo-qiang-jue");


        set("inquiry", ([
		"����" : (: cross_river :),
		"�ڶ�" : (: cross_river :), 
        ]) );
	
	create_family("�������", 16, "����");

	setup();
	add_money("coin", 200);
	carry_object("/obj/cloth")->wear();
	carry_object("/d/heimuya/obj/chuangao")->wield();

}

void init()
{
        add_action("do_chushi", "chushi");
        ::init();
}


int accept_object(object who, object ob)
{
		int val;

	        val = ob->value();
        	if( !val) return notify_fail("�Ҳ�Ҫ��Ʒ\n");


                if( ob->value() >= 4000 ) {
			destruct(ob);
			command("nod");
			message("vision", "�ҹ�˵���͹ٿ��Թ�������\n",who );
			this_player()->move("/d/heimuya/river1");
			call_out( "guohe", 2, who, 0 );
                        return 1;
                } else 
		   {
		    write("��ô�٣��һ�Ҫ����ѽ��\n");
		    return 0;	
		   }	
}

string	cross_river()
{
	return  "������̵��˲�ҪǮ,ֻ��Ҫ��ʾ(chushi)����\n������ÿ�ν���ʮ������";
}

int do_chushi()
{
	object who,*inv;
	int i;

	who=this_player();
	if(who->query("family/family_name")=="�������")
  	{
   	 inv = all_inventory(who);
   	 for(i=0; i<sizeof(inv); i++)
    	 {   
       	 if(strsrch(inv[i]->query("name"),"����")==-1)continue;
      	 write("������̵��ֵܹ��ӵ�Ȼ���!!.\n");
	 this_player()->move("/d/heimuya/river1");	 
	 call_out( "guohe", 2, who, 0 );

       	 return 1;
         }
	 write(HIR "����������Ķ�ȥ��?\n��ȥ��һ��!!\n" NOR);   
    	 return 1;
	}	
	else
           write(HIY "����ʵʵ��Ǯ��!!!\n" NOR);
	return 1;	
}

void guohe(object who, int stage)
{
     object obj;
     tell_object(who, make_msg[stage]);
     if( ++stage < sizeof(make_msg) ) {
         call_out( "guohe", 2, who, stage );
         return;
     } else
	who->move("/d/heimuya/xxt5");
        if(who->query("family/family_name")=="�������")
         {
	  tell_object(who,"�ֵ�,������,һ·˳��!\n");
	 }
	else
	 {
	  tell_object(who,"������,�����ȥ��!\n");
	 }
    return;
}
