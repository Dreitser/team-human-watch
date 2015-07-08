#include <pebble.h>

static Window *s_main_window;
static TextLayer *s_time_layer;
static TextLayer *s_stat_layer;
static TextLayer *s_twitter_layer;
static TextLayer *s_battery_layer;
static BitmapLayer *s_background_layer;
static GBitmap *s_background_bitmap;
static char s_str_example[] = "          TEAM HUMAN";
int human = 1;
int counter = 1;
int acceldecay =0;

static void update_time() {
  // Get a tm structure
  time_t temp = time(NULL); 
  struct tm *tick_time = localtime(&temp);
  

  // Create a long-lived buffer
  static char buffer[] = "00:00";
  static char buffer2[]= "                                                                                     ";
 // static char buffer3[] = "Twitter";
  
  // Write the current hours and minutes into the buffer
  if(clock_is_24h_style() == true) {
    // Use 24 hour format
    strftime(buffer, sizeof("00:00"), "%H:%M", tick_time);
  } else {
    // Use 12 hour format
    //strftime(buffer, sizeof("00:00 A"), "%I:%M %P", tick_time);
    strftime(buffer, sizeof("00:00"), "%I:%M", tick_time);
  }
  
  // Calculate Human Population
  int r = (temp*2) - 2770000000;
  snprintf(buffer2, sizeof(buffer2), "%s\n  7%d Teammates", s_str_example, r );
  
  // Generate Cool Humans
   switch (human) {
    // This is component that displays the image watchface
    case 1:
      // Cycle the icon
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_1);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@TeamHumanWatch");    
      break;
      
    case 2:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_2);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@DalaiLama");
      break;
     
    case 3:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_3);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@BarackObama");
      break;
      
    case 4:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_4);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@CarliLloyd");
      break;
     
    case 5:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_5);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@DavidOrtiz");
      break;
     
      case 6:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_6);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@TheRealBuzz");
      break;
     
      case 7:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_7);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@EricMigi");
      break;
     
      case 8:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_8);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@TaylorSwift13");
      break;
     
      case 9:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_9);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@DuncanTrussell");
      break;

      case 10:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_10);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@Oprah");
      break;
      
      case 11:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_11);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@TFerriss");
      break;

      case 12:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_12);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@SteveMaxwellSC");
      break;

      case 13:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_13);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@MikeTyson");
      break;
     
      case 14:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_14);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@NeilTyson");
      break;
      
      case 15:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_15);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@TheRock");
      break;
     
      case 16:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_16);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@justinbieber");
      break;
     
      case 17:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_17);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@BeingSalmanKhan");
      break;
     
      case 18:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_18);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@bkessler");

      break;
     
      case 19:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_19);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@elonmusk");
      break;
     
      case 20:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_20);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@JoeRogan");
      break;
     
      case 21:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_21);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@TheNotoriousMMA");
      break;
     
     case 22:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_22);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@GDIGM");
      break;
     
     case 23:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_23);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@PaulStamets");
      break;
     
    case 24:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_24);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@billclinton");
      break;
     
    case 25:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_25);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@HardcoreHistory");
      break;
      
    case 26:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_26);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@ID_AA_Carmack");
      break;
      
    case 27:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_27);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@StevenRinella");
      break;
      
    case 28:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_28);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@ConanOBrien");
      break;
     
    case 29:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_29);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@RondaRousey");
      break;
     
     case 30:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_30);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@Beyonce");
      break;
     
    case 31:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_31);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@PutinRF_Eng");
      break;
     
     case 32:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_32);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@JustinTheViking");
      break;
     
     case 33:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_33);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@SwiftAlphaOne");
      break;
     
     case 34:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_34);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@Bourdain");
      break;
     
     case 35:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_35);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@reshmasaujani");
      break;
     
     case 36:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_36);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@alexgreycosm");
      break;
     
     case 37:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_37);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@MileyCyrus");
      break;
     
    case 38:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_38);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@nicksahler");
      break;
     

    case 39:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_39);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@katyperry");
      break;

    case 40:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_40);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@Pontifex");
      break;

    case 41:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_41);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@glowascii");
      break;

    case 42:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_42);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@Pebble_Kat");
      break;

    case 43:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_43);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@JimCarrey");
      break;

    case 44:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_44);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@hannibalburess");
      break;

    case 45:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_45);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@madflavor");
      break;

    case 46:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_46);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@ActuallyNPH");
      break;

    case 47:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_47);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@AdamBenzion");
      break;

    case 48:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_48);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@VeganLunchTruck");
      break;

    case 49:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_49);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@shanesmith30");
      break;

    case 50:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_50);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@TannerSReid");
      break;

    case 51:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_51);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@sonnench");
      break;

    case 52:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_52);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@EmWatson");
      break;

    case 53:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_53);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@boone");
      break;

    case 54:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_54);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@JLo");
      break;

    case 55:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_55);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@NarendraModi");
      break;

    case 56:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_56);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@Madonna");
      break;

    case 57:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_57); 
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@davidsrose");
      break;

    case 58:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_58);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@JourdanUrbach");
      break;


      case 59:
      gbitmap_destroy(s_background_bitmap);
      s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_60);
      bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
      text_layer_set_text(s_twitter_layer, "@Dreitser");
      break;
     
      case 60:
       human = 1;
     break;


  }

  human++;
  
//   counter++;
//    if(counter%20 == 0){
//       human++;
//   }
  
  


  // buffer3 = " Twitter";
  text_layer_set_text(s_time_layer, buffer);
  text_layer_set_text(s_stat_layer, buffer2);
  battery_state_service_peek();

}

static void accel_handler(AccelData *data, uint32_t num_samples) {
  // If facing up Light It Up!!!
  if(((data[0].z < -980) && (data[0].z >-1020))&& ((data[1].z < -980) && (data[1].z >-1020)) && ((data[2].z < -980) && (data[2].z >-1020)) ){
    light_enable_interaction();
      update_time();
    }  
}
static void handle_battery(BatteryChargeState charge_state) {
  static char battery_text[] = "100% charged";

  if (charge_state.is_charging) {
    snprintf(battery_text, sizeof(battery_text), "Charging %d%%", charge_state.charge_percent);
  } else {
    snprintf(battery_text, sizeof(battery_text), "Bat: %d%% ", charge_state.charge_percent);
  }
  text_layer_set_text(s_battery_layer, battery_text);
  text_layer_set_size(s_battery_layer, (GSize){charge_state.charge_percent *1.44,20} ); 
}



static void main_window_load(Window *window) {
 // Create GBitmap, then set to created BitmapLayer
s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_1);
s_background_layer = bitmap_layer_create(GRect(0, 30, 144, 75));
bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_background_layer)); 
  
// Create time TextLayer
  s_time_layer = text_layer_create(GRect(0, 106, 144, 50));
  text_layer_set_background_color(s_time_layer, GColorClear);
  text_layer_set_text_color(s_time_layer, GColorBlack);
  text_layer_set_font(s_time_layer, fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD));
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);
  
   s_stat_layer = text_layer_create(GRect(0, 0, 144, 30));
  
   s_twitter_layer = text_layer_create(GRect(0, 101, 144, 16));
   text_layer_set_background_color(s_twitter_layer, GColorClear);
   text_layer_set_text_alignment(s_twitter_layer, GTextAlignmentCenter);
   text_layer_set_font(s_twitter_layer, fonts_get_system_font(FONT_KEY_GOTHIC_14));
  
   s_battery_layer = text_layer_create(GRect(0, 152, 144, 16));
   text_layer_set_background_color(s_battery_layer, GColorBlack);
   text_layer_set_text_color(s_battery_layer, GColorWhite);
   text_layer_set_font(s_battery_layer, fonts_get_system_font(FONT_KEY_GOTHIC_14));
  
//    s_heading_layer = text_layer_create(GRect(35, 150, 144, 16));
//    text_layer_set_font(s_heading_layer, fonts_get_system_font(FONT_KEY_GOTHIC_14));
//    text_layer_set_text(s_heading_layer, "00.0000  ");
  
  
   // Add as a child layer to the Window's root layer
   layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_stat_layer));
   layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_time_layer));
   layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_twitter_layer));
   layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_battery_layer));
;
  
    //layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_heading_layer));
  
    battery_state_service_subscribe(handle_battery);
   
}

static void main_window_unload(Window *window) {
   text_layer_destroy(s_time_layer);
   text_layer_destroy(s_stat_layer);
   text_layer_destroy(s_twitter_layer);
   text_layer_destroy(s_battery_layer);
  
  // Destroy GBitmap
  gbitmap_destroy(s_background_bitmap);
  // Destroy BitmapLayer
  bitmap_layer_destroy(s_background_layer);
  
  battery_state_service_unsubscribe();
  accel_data_service_unsubscribe();
   

}
static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  update_time();
  handle_battery(battery_state_service_peek());  
  
}
static void init() {
  // Register with TickTimerService
  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
  // Subscribe to the accelerometer data service
    int num_samples = 3;
    accel_data_service_subscribe(num_samples, accel_handler);

    // Choose update rate
    accel_service_set_sampling_rate(ACCEL_SAMPLING_10HZ);
// Create main Window element and assign to pointer
  s_main_window = window_create();
  
  #ifdef PBL_SDK_2
    window_set_fullscreen(s_main_window, true);
  #endif


  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  // Show the Window on the watch, with animated=true
  window_stack_push(s_main_window, true);
  update_time();
}

static void deinit() {
window_destroy(s_main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}