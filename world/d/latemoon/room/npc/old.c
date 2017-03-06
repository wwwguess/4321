
// old.c

inherit NPC;

void create()
{
	set_name("�����ϸ�", ({ "old" }) );
      set("title", "������" );
	set("long", "����ϸ��˲�֪������˭, �������ºܾ���, һֱ����\n�鷿, ��ׯ�����������𾴡�\n");
      set("gender", "Ů��" );
	set("age", 62);
	set("attitude", "peaceful");
	set("str", 20);
	set("cor", 26);
	set("cps", 26);
	set("per", 29);
	set("inquiry", ([
		"here": "�������鷿����Щ�޷��̲Ĵ���������",
		"trouble":
			"ʵ����������ɱ�����ҵ�˽��Ů������������; ...\n��һֱ�᲻������ɱ�����������ܰ�æ�һ�ǳ���л�� \nֻ��Ҫ������Ϊ֤���� ...",
		"����" : "�����Ҷ����� ...���õ��˾͸��ҡ�",
	]) );
      set("class", "dancer");
      set("combat_exp", 500000);
      set("score", 1000);
      set_skill("dodge", 70);
      set_skill("stormdance", 70);
      set_skill("tenderzhi", 70);
      set_skill("snowwhip", 60); 
      map_skill("dodge","stormdance");
      map_skill("whip","snowwhip"); 
      map_skill("unarmed","tenderzhi");
      set("force", 1000);
      set("max_force", 800);
      set("force_factor", 10);
      create_family("����ׯ", 1, "ǰ��");

      setup();
      carry_object("/d/latemoon/obj/deer_boot")->wear();
      carry_object("/d/latemoon/obj/blue_dress")->wear();
	carry_object("/u/cloud/obj/npc/lm_guard/whip")->wield();
}

int accept_object(object me, object ob)
{
        object book;	
        int iNeiLiTrans;
	if( !ob->id("###token###") ) return 0;
	command("sigh");
      if( (int)me->query( "max_force" ) < 160 
               && ((string)me->query("family/family_name")=="����ׯ") )
      {
         command("say ��Ϊ��л���Ҵ���һЩ������");
         message_vision( "�����ϸ��ֵ���$N�ĺ��ģ�ͷ��ð��˿˿������ \n", me );
         message( "vision", "��о���һ���������˹����� \n", me );
         iNeiLiTrans = 160-(int)me->query( "max_force" );
         if( iNeiLiTrans>50 ) 
             iNeiLiTrans = random( 50 );
         else
             iNeiLiTrans = random( iNeiLiTrans ); 
	 if( iNeiLiTrans > 20 ) iNeiLiTrans = 20;
	 iNeiLiTrans = iNeiLiTrans*(int)me->query_kar()/30; 
         me->set("max_force", (int)me->query("max_force")+iNeiLiTrans );
         me->set("force", 0);
      }
      else
      {
         command("say ��Ϊ��л���Ҹ���һ����ѩ�޷����š�");
         book = new(__DIR__"obj/whip_book");
         book->move(me);	
        //delete("inquiry/trouble");
	//delete("inquiry/����");
      }
	return 1;	
}
