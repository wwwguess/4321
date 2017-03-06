// shiao.c

inherit NPC;

void create()
{
	set_name("�����", ({ "adviser" }));
	set("title","��ʦ");
	set("gender", "����");
	set("age", 44);
	set("long",
        	"�������棬���ǲ��Զ��֣�������ǧ����Ȼ��éɽ�������еĸ�\n"
        	"�֣��������ȣ��ʹ󽫾����Ǿ��䡣\n");

	set("attitude", "peaceful");

	set("str", 20);
	set("int", 30);

	set("combat_exp", 300000);
        
        set("inquiry", ([
        	"������" : "�ȿ�����ĳ�����˵�ޡ�\n",
        ]) );
        
        set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
	        (: cast_spell, "drainerbolt" :),
	        (: cast_spell, "netherbolt" :),
	        (: cast_spell, "feeblebolt" :),
	        (: cast_spell, "invocation" :),
	}) );        
	
	set("force", 600);
	set("max_force", 600);
	set("force_factor", 5);
        
        set("atman", 600);
        set("max_atman", 600);
        
        set("mana", 2000);
        set("max_mana", 1200);
	set("mana_factor", 5);
	
        set_skill("literate", 60);
        set_skill("magic", 60);
        set_skill("force", 25);
        set_skill("spells", 80);
        set_skill("unarmed", 30);
        set_skill("sword", 40);
        set_skill("parry", 35);
        set_skill("dodge", 40);
        
        set_skill("taoism", 60);
        set_skill("necromancy", 70);
        set_skill("gouyee", 50);
        
        map_skill("magic", "taoism");
        map_skill("spells", "necromancy");
        map_skill("force", "gouyee");
        
        set_temp("apply/dodge",15);
        set_temp("apply/armor",15);
         
	setup();

	carry_object(__DIR__"obj/fan_sword")->wield();
	carry_object(__DIR__"obj/hat")->wear();
}

int accept_object(object who,object ob)
{
        if ( !ob->value() ) {
        	command("say ��....��hank ��ou!!!");
                command("grin");
              //  call_out( (: destruct :), 1, ob);
                return 1;
	}
                                                                                                                                                                
	if( !who->query_temp("��Ӫ/swear") ) {
		if( ob->value() >= 800 ) {
            	   command("say �ü��ˣ��Ҿ͸�����һ�����ܰɡ�");
            	   command("say ����Ƭ�⻬��ɽ��ǰ����(swear) �Ұ�.....��");
                   command("say ����\����Է������ص���ม�");
                   who->set_temp("��Ӫ/swear", 1);
		   return 1;
		} else {
		   command("say Ǯ̫���˰ɣ�û�ա�");
		   return 1;
		}
	} else 
		command("say ��Ȼ����ô���ģ����Ҿ���ǿ�������ˡ�");
	
	return 1;
}
